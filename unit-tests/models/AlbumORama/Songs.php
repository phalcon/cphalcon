<?php

namespace AlbumORama;

class Songs extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->hasMany('id', Albums::class, 'albums_id', array(
			'alias' => 'album'
		));
	}

}
