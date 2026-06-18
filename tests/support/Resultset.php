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

namespace Phalcon\Tests\Support;

/**
 * A simple value object used with PDO::FETCH_CLASS in DataMapper tests.
 * The constructor argument is stored as $calculated; database columns are
 * hydrated by PDO directly onto the public properties.
 */
class Resultset
{
    public string $calculated = '';

    public function __construct(string $calculated = '')
    {
        $this->calculated = $calculated;
    }
}
