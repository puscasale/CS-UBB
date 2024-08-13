from repo.repo_event import Repo
from service.service_event import Service
from domain.validator import Valid
from ui.console import Console
from tests.test import Test

repo = Repo('data/data.txt')
valid = Valid()
service = Service(repo, valid)
repo_test = Repo('data/test.txt')
service_test = Service(repo_test, valid)
test = Test(service_test)
test.run()
console = Console(service)
console.start()