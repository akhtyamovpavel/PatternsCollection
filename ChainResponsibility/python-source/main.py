from pathlib import Path

from handlers import BaseHandler
from handlers import DivisionZeroHandler
from handlers import FileHandler
from handlers import Log
from handlers import LogLevel
from handlers import StderrHandler


def report_error(error: Exception, log: Log) -> None:
    print(f"звено упало на записи {log}, но цепочка продолжила: {error}")


def main() -> None:
    log_path = Path("chain.log")

    # Цепочка собирается вызовами set_next, и каждый возвращает следующее звено.
    root = BaseHandler(LogLevel.all())
    root.set_error_function(report_error)

    broken = DivisionZeroHandler(LogLevel.all())
    broken.set_error_function(report_error)

    file_handler = FileHandler(log_path, LogLevel.all())
    stderr_handler = StderrHandler(LogLevel.problems())

    root.set_next(broken).set_next(file_handler).set_next(stderr_handler)

    records = [
        Log(LogLevel.DEBUG, "cache warmed up"),
        Log(LogLevel.INFO, "request handled"),
        Log(LogLevel.ERROR, "database is unreachable"),
    ]
    for record in records:
        print(f"--- отправляем: {record}")
        root.handle(record)

    print()
    print("в файл попало всё, потому что у него уровни all:")
    print(log_path.read_text(encoding="utf-8").rstrip())
    print()
    print("а в поток ошибок только предупреждения и ошибки")
    log_path.unlink()


if __name__ == "__main__":
    main()
