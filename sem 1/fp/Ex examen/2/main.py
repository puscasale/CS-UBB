from service.show_service import Service
from repo.show_repo import Repo
from validator import Validator
from ui.console import Console

repo = Repo('data/data.txt')
valid = Validator()
service = Service(repo, valid)
console = Console(service)
console.run()