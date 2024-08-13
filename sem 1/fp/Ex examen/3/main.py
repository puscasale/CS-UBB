from service.exam_service import Service
from validator import Validator
from repo.exam_repo import Repo
from ui.console import Console
from tests.tests import Tests

repo = Repo('data/data.txt')
valid = Validator()
service = Service(repo, valid)

repo_test = Repo('tests/data_test.txt')
service_test = Service(repo_test, valid)
tests = Tests(service_test)
tests.run()
console = Console(service)
console.run()
