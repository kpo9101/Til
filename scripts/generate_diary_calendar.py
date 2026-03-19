import calendar
from datetime import datetime
import os

KOREAN_WEEKDAYS = ['월', '화', '수', '목', '금', '토', '일']

def generate_month_calendar(year: int, month: int) -> str:
    cal = calendar.monthcalendar(year, month)
    markdown = f"<details>\n<summary><strong>📅 {year}년 {month}월</strong></summary>\n\n"
    markdown += "| " + " | ".join(["월", "화", "수", "목", "금", "토", "일"]) + " |\n"
    markdown += "| " + " | ".join(["---"] * 7) + " |\n"

    for week in cal:
        row = []
        for day in week:
            if day == 0:
                row.append(" ")
            else:
                date_str = f"{year}.{month:02d}.{day:02d}"
                weekday = KOREAN_WEEKDAYS[calendar.weekday(year, month, day)]
                filename = f"{date_str}.{weekday}.md"
                link = f"[{date_str}.{weekday}](다이어리/{filename})"
                row.append(link)
        markdown += "| " + " | ".join(row) + " |\n"
    markdown += "\n</details>\n\n"
    return markdown

with open("README.md", "r", encoding="utf-8") as f:
    content = f.read()

start = content.find("<!-- DIARY_CALENDAR_START -->") + len("<!-- DIARY_CALENDAR_START -->")
end = content.find("<!-- DIARY_CALENDAR_END -->")

new_calendar = ""
for m in range(3, 13):                    # 2026년 전체 12개월
    new_calendar += generate_month_calendar(2026, m)

new_content = content[:start] + "\n\n" + new_calendar + content[end:]

with open("README.md", "w", encoding="utf-8") as f:
    f.write(new_content)

print("✅ 다이어리 달력 자동 업데이트 완료!")
