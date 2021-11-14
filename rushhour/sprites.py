from imageio import imread

for name in ['board', 'car1', 'car2', 'car3', 'car4', 'car5', 'wall']:
  image = imread('sprites/' + name + '.png')
  result = 'static const uint16_t %s[] = {' % name
  for y in range(image.shape[0]):
    for x in range(image.shape[1]):
      r = image[y][x][0] >> 3
      g = image[y][x][1] >> 2
      b = image[y][x][2] >> 3
      rgb = (r << 11) | (g << 5) | b
      result += '0x%04x, ' % rgb
  print(result[:-2] + '};')
