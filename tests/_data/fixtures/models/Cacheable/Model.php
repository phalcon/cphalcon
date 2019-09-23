<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Cacheable;

use Phalcon\Mvc\Model as PhalconModel;

class Model extends PhalconModel
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
            unset($parameters['di']);
        }

        $key = md5(
            get_called_class() . serialize($parameters)
        );

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
