# 📚 Bài Tập Thực Hành 5 - Lập Trình Hướng Đối Tượng (IT002)

**Họ và tên:** Bảo Trình  
**MSSV:** 25521929  

---

## 📂 Cấu trúc kho lưu trữ

| Thư mục | Nội dung bài tập | Mô tả kỹ thuật nổi bật |
| :--- | :--- | :--- |
| `bai1_lab5` | Quản lý nhân viên (Sản xuất, Văn phòng) | Xây dựng lớp cha/con, áp dụng đa hình (`virtual`) tính lương, dùng `dynamic_cast` tìm kiếm đặc thù. |
| `bai2_lab5` | Quản lý giao dịch BĐS (Đất, Nhà, Chung cư) | Kế thừa, ghi đè hàm tính tiền theo hệ số riêng của từng loại giao dịch. |
| `bai3_lab5` | Quản lý Sinh viên (Cao đẳng, Đại học) | Hàm thuần ảo kiểu `bool` xét điều kiện tốt nghiệp, lọc danh sách sinh viên. |
| `bai4_lab5` | Công ty phần mềm (Lập trình, Kiểm chứng) | Xử lý Input Validation (bẫy lỗi số âm), thống kê lương Min/Max, Lương trung bình. |
| `bai6_lab5` | Quản lý khách hàng (Loại A, B, C) | Kết hợp Đa hình với Đọc/Ghi file văn bản (`XYZ.INP`, `XYZ.OUT`), logic hàm `min` tính giới hạn khuyến mãi. |

---

## 🛠 Hướng dẫn biên dịch
Để biên dịch và chạy bất kỳ bài nào, vui lòng mở Terminal, di chuyển vào thư mục tương ứng và sử dụng chuỗi lệnh sau:

```bash
g++ *.cpp -o main && ./main
