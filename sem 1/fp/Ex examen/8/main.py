from domain.echipa_domain import Echipa
from domain.validator import Validate
from repo.echipa_repo import Repo
from service.echipa_service import Service
from tests.tests import Test
from ui.console import Console

repo = Repo('data/data.txt')
valid = Validate()
service = Service(repo, valid)
repo_test = Repo('data/test.txt')
service_test = Service(repo_test, valid)
test = Test(service_test)
test.run()
console = Console(service)
console.run()
