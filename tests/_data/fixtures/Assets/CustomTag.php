<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Assets;

class CustomTag extends \Phalcon\HtmlTag
{
    public function stylesheet(string $url, array $parameters = []): string
    {
        return sprintf(
            "<link href=\"%s\">\n",
            $url
        );
    }

    public function javascript(string $url, array $parameters = []): string
    {
        return sprintf(
            "<script src=\"%s\" type=\"application/javascript\"></script>\n",
            $url
        );
    }
}
