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

namespace Phalcon\Tests\Unit\Config\Config;

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\ConfigTrait;

final class GetTest extends AbstractUnitTestCase
{
    use ConfigTrait;

    /**
     * @author Cameron Hall <me@chall.id.au>
     * @since  2019-06-17
     */
    public function testConfigGet(): void
    {
        $config = $this->getConfig();

        $expected = $this->config['database']['adapter'];
        $actual   = $config->get('database')
                           ->get('adapter')
        ;
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Cameron Hall <me@chall.id.au>
     * @since  2019-06-17
     */
    public function testConfigGetter(): void
    {
        $config = $this->getConfig();

        $expected = $config->database->adapter;
        $actual   = $this->config['database']['adapter'];
        $this->assertSame($expected, $actual);
    }
}
