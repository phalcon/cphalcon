<?php

namespace AlbumORama;

class Albums extends \Phalcon\Mvc\Model
{

	public function initialize()
	{
		$this->belongsTo('artists_id', Artists::class, 'id', array(
			'alias' => 'artist'
		));
		$this->hasMany('id', Songs::class, 'albums_id', array(
			'alias' => 'songs'
		));
	}

}
