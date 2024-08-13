from domain.validator import Valid
from repo.repo_biblio import Repo
from service.serice_biblio import Service
from ui.console import Console

repo = Repo('data/data.txt')
valid = Valid()
service = Service(repo, valid)
console = Console(service)
console.run()
