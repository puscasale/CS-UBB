from domain.song_domain import Song
from domain.validator import Validator
from repo.song_repo import Repo
from service.song_service import Service
from ui.console import Console

repo = Repo('data/data.txt')
valid = Validator()
service = Service(repo, valid)
console = Console(service)
console.run()
