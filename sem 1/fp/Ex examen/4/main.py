from repo.emisiune_repo import Repo
from service.emisiune_service import Service
from ui.console import Console
from tests.tests import Test

repo = Repo('data/data.txt')
service = Service(repo)
console = Console(service)
repo_test = Repo('tests/data_tests.txt')
service_test = Service(repo_test)
tests = Test(service_test)
console.start()
