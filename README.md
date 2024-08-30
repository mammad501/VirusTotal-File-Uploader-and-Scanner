VirusTotal File Uploader







توضیحات
این برنامه به زبان C++ نوشته شده و به شما امکان می‌دهد یک فایل را به VirusTotal آپلود کرده و نتایج اسکن آن را مشاهده کنید. با استفاده از این برنامه، می‌توانید بفهمید که آیا فایل شما توسط آنتی‌ویروس‌های مختلف به عنوان بدافزار شناسایی شده است یا خیر.

وابستگی‌ها
libcurl: برای ارسال درخواست‌های HTTP
nlohmann/json: برای تجزیه JSON

نصب (لینوکس)
sudo apt-get install libcurl4-openssl-dev
sudo apt-get install nlohmann-json3-dev


استفاده
برنامه را کامپایل و اجرا کنید.
مسیر فایل موردنظر را وارد کنید.
نتیجه اسکن به شما نمایش داده می‌شود:
اگر فایل پاک باشد، پیام مناسب نمایش داده می‌شود.
اگر فایل آلوده باشد، نام آنتی‌ویروس‌هایی که آن را شناسایی کرده‌اند نمایش داده می‌شود.
نکته
قبل از استفاده، کلید API خود را در کد جایگزین کنید.
