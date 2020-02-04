<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Assets;

class CustomTag extends \Phalcon\Tag
{
    public static function stylesheetLink($parameters = null, bool $local = true): string
    {
        return sprintf(
            "<link href=\"%s\">\n",
            $parameters[0]
        );
    }

    public static function javascriptInclude($parameters = null, bool $local = true): string
    {
        return sprintf(
            "<script src=\"%s\" type=\"application/javascript\"></script>\n",
            $parameters[0]
        );
    }
}
