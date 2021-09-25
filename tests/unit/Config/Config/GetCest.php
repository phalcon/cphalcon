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

use Phalcon\Tests\Fixtures\Traits\ConfigTrait;
use UnitTester;

class GetCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config :: __get()
     *
     * @author Cameron Hall <me@chall.id.au>
     * @since  2019-06-17
     */
    public function configGetter(UnitTester $I)
    {
        $I->wantToTest('Config - get()');
        $config = $this->getConfig();
        $I->assertEquals(
            $config->database->adapter,
            $this->config['database']['adapter']
        );
    }

    /**
     * Tests Phalcon\Config :: __get()
     *
     * @author Cameron Hall <me@chall.id.au>
     * @since  2019-06-17
     */
    public function configGet(UnitTester $I)
    {
        $I->wantToTest('Config - get()');
        $config = $this->getConfig();
        $I->assertEquals(
            $config->get('database')->get('adapter'),
            $this->config['database']['adapter']
        );
    }
}
