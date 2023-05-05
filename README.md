# FirePG2

## Introductions
- Đây là một game được viết bằng ngôn ngữ C++, dùng thư viện SDL2.
- Xem demo tại [đây](https://www.youtube.com/watch?v=iATIGjhpyLo)
## Contents
- Người chơi sẽ điều khiển một xe tăng để đi khám phá mê cung.
- Xuất phát từ góc trái trên của bản đồ, người chơi cần đi đến đích ở góc phải dưới.
- Trên đường đi xe tăng sẽ phải đối đầu với các xe tăng địch, cần tiêu diệt chúng để nhận điểm số. Sau khi địch chết sẽ ra một lượng máu, di chuyển đến vị trí đó để nhặt máu.
- Sau khi đến ô phải dưới, người chơi sẽ được chuyển đến một bản đồ mới, cộng một lượng điểm số lớn. Game sẽ chơi vô hạn cho đến khi nhân vật chính bị tiêu diệt.
## Technologies
  * *IDE:*
Code::Blocks 20.03
  * *Thư viện:*
SDL2-2.26.3, SDL2_image-2.6.3, SDL2_ttf-2.20.2, SDL2_mixer-2.6.3
## How to play
  ### 1. Nút bấm trong menu
  - *RESTART:* Bắt đầu game mới
  - *RESUME:* Tiếp tục game sau khi tạm dừng
  - *EXIT:* Thoát trò chơi
  ### 2. Điều khiển trò chơi
  - *ESC:* Tạm dừng trò chơi, quay về menu
  - *W:* Di chuyển lên trên
  - *S:* Di chuyển xuống dưới
  - *D:* Di chuyển sang phải
  - *A:* Di chuyển sang trái
  - *Chuột trái:* Bắn đạn bay thẳng theo hướng con trỏ chuột
  - *E:* Sử dụng chiêu thức, cho ra một tên lửa di chuyển theo kẻ địch
## Algorithms
  - Game sử dụng thuật toán *Tìm kiếm theo chiều sâu(DFS)* để xây dựng một mê cung ngẫu nhiên https://en.wikipedia.org/wiki/Maze_generation_algorithm
  - Các đối tượng xe tăng địch luôn phải đuối theo nhân vật chính. Sử dụng thuật toán *BFS* để xử lí.
