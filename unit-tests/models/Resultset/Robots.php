<?php

namespace Resultset;

class Robots extends \Phalcon\Mvc\Model
{
	public static function cloneResultMap($base, $data, $column_map, $dirty_state = 0, $keep_snapshots = NULL, $source_model = NULL) {
		return new \ArrayObject($data);
	}
}