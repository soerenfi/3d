#include "camera.h"
#include "color.h"
#include "prim_list.h"
#include "rt_util.h"
#include "sphere.h"
#include <fstream>
#include <iostream>

color ray_color(const ray& r, const prim& stage) {
  hit_record rec;
  if (stage.hit(r, 0, infinity, rec)) {
    return 0.5 * (rec.normal + color(1, 1, 1));
  }
  vec3 unit_direction = unit_vector(r.direction());
  auto t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main() {
  // Image

  const auto aspect_ratio = 16.0 / 9.0;
  const int image_width = 800;
  const int image_height = static_cast<int>(image_width / aspect_ratio);
  const int samples_per_pixel = 16;

  // World
  prim_list stage;
  stage.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
  stage.add(make_shared<sphere>(point3(0, -100.5, -1), 100));
  stage.add(make_shared<sphere>(point3(0, -120, -1), 130));

  // Camera
  camera cam;

  // Render

  std::ofstream outfile;
  outfile.open("image.raw");  // opens the file

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = image_height - 1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i) {
      color pixel_color(0, 0, 0);
      for (int s = 0; s < samples_per_pixel; ++s) {
        auto u = (i + random_double()) / (image_width - 1);
        auto v = (j + random_double()) / (image_height - 1);
        ray r = cam.get_ray(u, v);
        pixel_color += ray_color(r, stage);
      }
      write_color(outfile, pixel_color, samples_per_pixel);
    }
  }

  std::cerr << "\nDone.\n";
}
