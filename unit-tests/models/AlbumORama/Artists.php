<?php

namespace AlbumORama;

class Artists extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->hasMany('id', 'AlbumORama\Albums', 'artists_id', array(
			'alias' => 'albums'
		));
	}

}