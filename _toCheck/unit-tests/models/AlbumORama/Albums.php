<?php

namespace AlbumORama;

class Albums extends \Phalcon\Mvc\Model
{

    public function initialize()
    {
        $this->belongsTo('artists_id', 'AlbumORama\Artists', 'id', [
            'alias' => 'artist',
        ]);
        $this->hasMany('id', 'AlbumORama\Songs', 'albums_id', [
            'alias' => 'songs',
        ]);
    }

}
