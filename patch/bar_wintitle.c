int
width_wintitle(Bar *bar, BarArg *a)
{
	return a->w;
}

int
draw_wintitle(Bar *bar, BarArg *a)
{
	int x = a->x + lrpad / 2, w = a->w - lrpad;
	Monitor *m = bar->mon;
	int pad = lrpad / 2;

	if (!m->sel) {
		drw_setscheme(drw, scheme[SchemeTitleNorm]);
		drw_rect(drw, x, a->y, w, a->h, 1, 1);
		return 0;
	}

	drw_setscheme(drw, scheme[m == selmon ? SchemeTitleSel : SchemeTitleNorm]);
	if (TEXTW(m->sel->name) < w)
		pad = (w - TEXTW(m->sel->name) + lrpad) / 2;
	drw_text(drw, x, a->y, w, a->h, pad, m->sel->name, 0, False);
	drawstateindicator(m, m->sel, 1, x, a->y, w, a->h, 0, 0, m->sel->isfixed);
	return 1;
}

int
click_wintitle(Bar *bar, Arg *arg, BarArg *a)
{
	return ClkWinTitle;
}


