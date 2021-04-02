<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Assets;

class CustomTag extends \Phalcon\Tag
{
    public static function stylesheetLink($parameters = null, bool $local = true): string
    {
        return sprintf(
            "<link href=\"%s\">" . PHP_EOL,
            $parameters[0]
        );
    }

    public static function javascriptInclude($parameters = null, bool $local = true): string
    {
        return sprintf(
            "<script src=\"%s\" type=\"application/javascript\"></script>" . PHP_EOL,
            $parameters[0]
        );
    }
}
