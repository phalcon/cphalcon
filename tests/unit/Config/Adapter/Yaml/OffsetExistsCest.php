<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Config\Adapter\Yaml;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class OffsetExistsCest
{
    use ConfigTrait;

    /**
     * @param UnitTester $I
     */
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('yaml');
    }

    /**
     * Tests Phalcon\Config\Adapter\Yaml :: offsetExists()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configAdapterYamlOffsetExists(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Yaml - offsetExists()');
        $this->checkOffsetExists($I, 'Yaml');
    }
}
