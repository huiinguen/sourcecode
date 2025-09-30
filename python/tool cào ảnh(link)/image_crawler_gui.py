import tkinter as tk
import ttkbootstrap as ttk
from ttkbootstrap.constants import *
from tkinter import filedialog, messagebox
import requests
from bs4 import BeautifulSoup
import os
from urllib.parse import urljoin, urlparse
import threading
from datetime import datetime
from PIL import Image
from io import BytesIO

def create_image_crawler_frame(parent):
    frame = ttk.Frame(parent, padding=10)

    ttk.Label(frame, text="🖼️ Cào ảnh từ website", font=("Helvetica", 16, "bold"), bootstyle=PRIMARY).pack(pady=10)

    # Ô nhập link
    ttk.Label(frame, text="🔗 Nhập link website:", bootstyle=SECONDARY).pack(anchor="w")
    url_entry = ttk.Entry(frame, width=70, bootstyle=PRIMARY)
    url_entry.pack(pady=5, fill="x")

    # Chọn thư mục lưu
    save_dir = tk.StringVar(value=os.path.join(os.getcwd(), "images"))
    path_frame = ttk.Frame(frame)
    path_frame.pack(fill="x", pady=5)
    ttk.Label(path_frame, text="📂 Thư mục lưu ảnh:", bootstyle=SECONDARY).pack(side="left")
    path_entry = ttk.Entry(path_frame, textvariable=save_dir, width=50)
    path_entry.pack(side="left", padx=5, fill="x", expand=True)

    def choose_dir():
        folder = filedialog.askdirectory()
        if folder:
            save_dir.set(folder)
    ttk.Button(path_frame, text="Chọn...", command=choose_dir, bootstyle=INFO).pack(side="left")

    # Ghi chú về tính năng
    ttk.Label(frame, text="🛠️ Chế độ: Cào tất cả ảnh trên trang", font=("Helvetica", 12, "italic"), bootstyle=SUCCESS).pack(anchor="w", pady=10)
    ttk.Label(frame, text="🔍 Các tính năng khác (cào theo từ khóa, AI) đang được phát triển...", font=("Helvetica", 10), bootstyle=INFO).pack(anchor="w")

    # Khu vực log và thanh tiến trình
    log_text = tk.Text(frame, height=12, wrap="word", bg="#1e1e1e", fg="#0f0", font=("Consolas", 10))
    log_text.pack(fill="both", expand=True, pady=(10, 5))
    
    progress_bar = ttk.Progressbar(frame, mode="determinate", bootstyle=SUCCESS)
    progress_bar.pack(fill="x", pady=5)

    def log(msg):
        log_text.insert(tk.END, msg + "\n")
        log_text.see(tk.END)

    def crawl_images(url, base_folder):
        try:
            log("🌐 Đang kết nối...")
            domain = urlparse(url).netloc.replace("www.", "")
            timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
            folder = os.path.join(base_folder, f"{domain}_{timestamp}")
            os.makedirs(folder, exist_ok=True)
            log(f"📂 Thư mục ảnh: {folder}")

            response = requests.get(url, headers={"User-Agent": "Mozilla/5.0"}, timeout=10)
            if response.status_code != 200:
                log(f"❌ Lỗi tải trang: {response.status_code}")
                return

            soup = BeautifulSoup(response.text, "html.parser")
            img_tags = soup.find_all("img")
            
            log(f"🔍 Tìm thấy {len(img_tags)} ảnh trên trang.")
            
            img_urls_to_download = [urljoin(url, img.get("src")) for img in img_tags if img.get("src")]
            
            log(f"✅ Tìm thấy {len(img_urls_to_download)} ảnh để tải về.")
            
            if not img_urls_to_download:
                log("❗ Không tìm thấy ảnh nào.")
                progress_bar['value'] = 0
                return
            
            progress_bar['maximum'] = len(img_urls_to_download)
            
            for idx, img_url in enumerate(img_urls_to_download, start=1):
                try:
                    response = requests.get(img_url, timeout=10)
                    if response.status_code != 200:
                        log(f"⚠️ Lỗi tải ảnh ({response.status_code}): {img_url}")
                        continue
                        
                    file_name = os.path.basename(urlparse(img_url).path)
                    if not file_name.lower().endswith(('.jpg', '.jpeg', '.png', '.gif', '.bmp')):
                        file_name = f"image_{idx}.jpg"
                    
                    file_path = os.path.join(folder, file_name)
                    
                    try:
                        img_data = response.content
                        Image.open(BytesIO(img_data)).verify() 
                        with open(file_path, "wb") as f:
                            f.write(img_data)
                        log(f"✅ Đã lưu ({idx}/{len(img_urls_to_download)}): {file_name}")
                    except (IOError, OSError) as e:
                        log(f"⚠️ Lỗi xử lý file ảnh: {file_name}. Bỏ qua.")
                        continue
                        
                except Exception as e:
                    log(f"❌ Lỗi khi tải ảnh: {e}")
                
                progress_bar['value'] = idx
                
            log("🎉 Hoàn tất quá trình cào ảnh!")
            
        except requests.exceptions.RequestException as e:
            log(f"❌ Lỗi kết nối: {e}")
        except Exception as e:
            log(f"❌ Lỗi không xác định: {e}")
        finally:
            progress_bar['value'] = 0
            
    def start_crawl():
        url = url_entry.get().strip()
        folder = save_dir.get()
        
        if not url:
            log("❌ Vui lòng nhập link website.")
            return

        log_text.delete("1.0", tk.END) 
        threading.Thread(target=crawl_images, args=(url, folder,), daemon=True).start()

    # Nút điều khiển
    btn_frame = ttk.Frame(frame)
    btn_frame.pack(pady=10)
    ttk.Button(btn_frame, text="🚀 Bắt đầu cào ảnh", bootstyle=SUCCESS, command=start_crawl).pack(side="left", padx=5)

    ttk.Label(frame, text="📌 Ghi chú: Thư mục ảnh được tự động tạo theo domain + thời gian.", 
              font=("Helvetica", 9), bootstyle=INFO, justify="left").pack(pady=10, anchor="w")

    frame.pack(fill="both", expand=True)
    return frame
# --- PHẦN BỔ SUNG ĐỂ CHẠY ĐỘC LẬP ---
if __name__ == "__main__":
    # Khởi tạo cửa sổ chính với ttkbootstrap
    app = ttk.Window(themename="superhero") # Có thể chọn theme khác, ví dụ: "superhero", "darkly", "cosmo"
    app.title("Image Crawler GUI - Công cụ Cào ảnh")
    app.geometry("800x650") # Thiết lập kích thước cửa sổ

    # Tạo frame cào ảnh và đặt nó vào cửa sổ chính
    crawler_frame = create_image_crawler_frame(app)
    
    # Chạy vòng lặp sự kiện chính của tkinter
    app.mainloop()