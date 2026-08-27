from __future__ import annotations

import sys

from .BaseHandler import BaseHandler
from .Log import Log


class StderrHandler(BaseHandler):
    """Печатает запись в поток ошибок."""

    def process(self, log: Log) -> None:
        print(str(log), file=sys.stderr)
