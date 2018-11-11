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

use Phalcon\Assets\FilterInterface;

class UppercaseFilter implements FilterInterface
{
    /**
     * Converts the input to uppercase
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-05
     *
     * @param string $content
     *
     * @return string
     */
    public function filter(string $content): string
    {
        return strtoupper($content);
    }
}
