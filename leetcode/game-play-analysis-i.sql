select a.player_id as player_id, MIN(a.event_date) as first_login
from Activity a
group by a.player_id