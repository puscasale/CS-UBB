from ui.console import Console
from service.service_tractor import Service
from repo.repo_tractor import Repo
from domain.tractor import Tractor

repo = Repo("data/data.txt")
service = Service(repo)
console = Console(service)
console.start()
