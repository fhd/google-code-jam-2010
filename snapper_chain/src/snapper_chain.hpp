inline int snaps_required_for(int snappers)
{
   if (snappers == 1)
      return 1;
   return snaps_required_for(snappers - 1) * 2 + 1;
}

inline bool is_light_bulb_on(int snappers, int snaps)
{
   int snaps_required = snaps_required_for(snappers);
   for (; snaps > snaps_required; snaps -= snaps_required + 1);
   return snaps == snaps_required;;
}
