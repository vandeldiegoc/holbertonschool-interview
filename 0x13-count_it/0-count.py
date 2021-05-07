#!/usr/bin/python3
""" recursive """
from requests import get


def count_words(subreddit, word_list, after="", _pair={}):
    """ count_words """
    if not _pair:
        for word in word_list:
            _pair[word] = 0

    if after is None:
        word_list = [[key, value] for key, value in _pair.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))
        for wd in word_list:
            if wd[1]:
                print("{}: {}".format(wd[0].lower(), wd[1]))
        return None

    url = "https://www.reddit.com/" + "r/{}/hot/.json".format(subreddit)

    res = get(url, headers={'user-agent': 'vandel'},
              params={'limit': 100, 'after': after}, allow_redirects=False)

    if res.status_code != 200:
        return None

    try:
        js = res.json()

    except ValueError:
        return None

    try:

        data = js.get("data")
        after = data.get("after")
        children = data.get("children")
        for child in children:
            post = child.get("data")
            title = post.get("title")
            lower = [sp.lower() for sp in title.split(' ')]

            for wd in word_list:
                _pair[wd] += lower.count(wd.lower())

    except Exception:
        return None

    count_words(subreddit, word_list, after, _pair)
