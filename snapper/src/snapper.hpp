int snaps_required_for(int snappers) {
    if (snappers == 1)
        return 1;
    return snaps_required_for(snappers - 1) * 2 + 1;
}

bool is_light_bulb_on(int snappers, int snaps)
{
   int snaps_required = snaps_required_for(snappers);
   if (snaps_required > snaps)
      return false;
   if (snaps_required == snaps)
      return true;
   return is_light_bulb_on(snappers, snaps - (snaps_required + 1));
}
