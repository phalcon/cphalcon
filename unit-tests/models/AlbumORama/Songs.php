<?php

namespace AlbumORama;

class Songs extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->hasMany('id', 'AlbumORama\Albums', 'albums_id', array(
			'alias' => 'album'
		));
	}

}