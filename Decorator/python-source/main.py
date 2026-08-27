from pathlib import Path

from notifiers import EmailNotifier
from notifiers import LogNotifier
from notifiers import TelegramNotifier


def main() -> None:
    log_path = Path("notifications.log")

    # Цепочка собирается снаружи внутрь: письмо оборачивает мессенджер,
    # мессенджер оборачивает запись в файл. Порядок задаёт порядок отправки.
    notifier = EmailNotifier(
        TelegramNotifier(
            LogNotifier(log_path),
            chat_id="42",
        ),
        address="oncall@example.com",
    )
    notifier.notify("service is down")

    print()
    print("Тот же набор, но собранный иначе:")

    # Ни один класс не изменился, изменился только порядок обёрток.
    another = TelegramNotifier(
        EmailNotifier(LogNotifier(log_path)),
        chat_id="7",
    )
    another.notify("service is back")

    print()
    print("в файле оказалось:")
    print(log_path.read_text(encoding="utf-8").rstrip())
    log_path.unlink()


if __name__ == "__main__":
    main()
