#ifndef IR
#define IR

#include <xwiimote.h>
#include <xf86Xinput.h>


#define IR_AVG_RADIUS 10
#define IR_AVG_MAX_SAMPLES 8
#define IR_AVG_MIN_SAMPLES 4
#define IR_AVG_WEIGHT 3
#define IR_CONTINUOUS_SCROLL_BORDER 20
#define IR_CONTINUOUS_SCROLL_MAX_X 10
#define IR_CONTINUOUS_SCROLL_MAX_Y 10
#define IR_MAX_Y 767
#define IR_MAX_X 1023
#define IR_SMOOTH_SCROLL_DISTANCE 1.0

#define IR_KEYMAP_EXPIRY_SECS 1

#define XWIIMOTE_DISTSQ(ax, ay, bx, by) \
	((ax - bx) * (ax - bx) + (ay - by) * (ay - by))

struct ir {
	struct timeval last_valid_event;
	int vec_x;
	int vec_y;
	int ref_x;
	int ref_y;
	int avg_x;
	int avg_y;
	int avg_count;

  double continuous_scroll_subpixel_x;
  double continuous_scroll_subpixel_y;

  double smooth_scroll_x;
  double smooth_scroll_y;
};

struct ir_config {
	int avg_radius;
	int avg_weight;
	int avg_max_samples;
	int avg_min_samples;
	int keymap_expiry_secs;
	int continuous_scroll_border;
  int continuous_scroll_max_x;
  int continuous_scroll_max_y;
};


BOOL ir_is_active(struct ir *ir, struct ir_config *config, struct xwii_event *ev);
void configure_ir(struct ir_config *config, char const *name, InputInfoPtr info);
void preinit_ir (struct ir_config *config);


void handle_ir(struct ir *ir, struct ir_config *config, struct xwii_event *ev, InputInfoPtr info);


#endif