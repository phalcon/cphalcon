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

namespace Phalcon\Tests\Unit\Config\Adapter\Yaml;

use Phalcon\Tests\Fixtures\Traits\ConfigTrait;
use UnitTester;

class GetCest
{
    use ConfigTrait;

    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('yaml');
    }

    /**
     * Tests Phalcon\Config\Adapter\Yaml :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-21
     */
    public function configAdapterYamlGet(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Yaml - get()');

        $this->checkGet($I, 'Yaml');
    }
}
