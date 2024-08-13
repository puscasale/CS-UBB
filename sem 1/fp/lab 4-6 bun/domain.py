
competitors = []


def get_id(competitor):
    return competitor[0]

def get_score(competitor):
    return competitor[1]

def set_id(competitor, id):
    competitor[0] = id

def set_score(competitor, score):
     competitor[1] = score

"""
competitors = []

def get_id(competitor):
    return competitor['competitor_nr']


def get_score(competitor):
    return competitor['contest_score']


def set_id(competitor, id):
    competitor['contest_score'] = id


def set_score(competitor, score):
    competitor['contest_score'] = score
"""
def create_competitor(contest_nr, score):
    return [contest_nr, score]
    #return dict(competitor_nr = contest_nr, contest_score = score )