Length Array: <?php echo $this->length($arr); ?>
Length Object: <?php echo $this->length($obj); ?>
Length String: <?php echo $this->length($str); ?>
Length No String: <?php echo $this->length($no_str); ?>
Slice Array: <?php echo join($this->slice($arr, 0, null), ','); ?>
Slice Array: <?php echo join($this->slice($arr, 1, 2), ','); ?>
Slice Array: <?php echo join($this->slice($arr, null, 2), ','); ?>
Slice Object: <?php echo join($this->slice($obj, 1, null), ','); ?>
Slice Object: <?php echo join($this->slice($obj, 1, 2), ','); ?>
Slice Object: <?php echo join($this->slice($obj, null, 1), ','); ?>
Slice String: <?php echo $this->slice('hello', null, 2); ?>
Slice String: <?php echo $this->slice('hello', 1, 2); ?>
Slice String: <?php echo $this->slice('hello', 2, null); ?>
Slice No String: <?php echo $this->slice(1234, null, 2); ?>
Slice No String: <?php echo $this->slice(1234, 1, 2); ?>
Slice No String: <?php echo $this->slice(1234, 2, null); ?>