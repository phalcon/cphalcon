<?php

namespace Cacheable;

class Model extends \Phalcon\Mvc\Model
{

    public static function findFirst($parameters = null)
    {
        $parameters = self::getCacheableParams($parameters);
        return parent::findFirst($parameters);
    }

    public static function getCacheableParams($parameters)
    {

        if (!$parameters) {
            return $parameters;
        }

        if (isset($parameters['di'])) {
            unset ($parameters['di']);
        }

        $key = md5(get_called_class() . serialize($parameters));

        if (!is_array($parameters)) {
            $parameters = [$parameters];
        }

        $parameters['cache'] = [
            'key'      => $key,
            'lifetime' => 3600,
        ];

        return $parameters;
    }

    public static function find($parameters = null)
    {
        $parameters = self::getCacheableParams($parameters);
        return parent::find($parameters);
    }

}
