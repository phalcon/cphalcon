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

namespace Phalcon\Tests\Unit\Config\Adapter\Ini;

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\ConfigTrait;

final class ToArrayTest extends AbstractUnitTestCase
{
    use ConfigTrait;

    /**
     * @author kjdev
     * @since  2013-07-18
     */
    public function testConfigAdapterIniToArray(): void
    {
        $this->config['database']['num1'] = false;
        $this->config['database']['num2'] = false;
        $this->config['database']['num3'] = false;
        $this->config['database']['num4'] = true;
        $this->config['database']['num5'] = true;
        $this->config['database']['num6'] = true;
        $this->config['database']['num7'] = null;
        $this->config['database']['num8'] = 123;
        $this->config['database']['num9'] = 123.45;

        $config = $this->getConfig('Ini');

        $expected = $this->config;
        $actual   = $config->toArray();
        $this->assertSame($expected, $actual);
    }
}
