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

class PathCest
{
    use ConfigTrait;

    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('yaml');
    }

    /**
     * Tests Phalcon\Config\Adapter\Yaml :: path()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function configAdapterYamlPath(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Yaml - path()');

        $this->checkPath($I, 'Yaml');
    }

    /**
     * Tests Phalcon\Config\Adapter\Yaml :: path() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function configAdapterYamlPathDefault(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Yaml - path() - default');

        $this->checkPathDefault($I, 'Yaml');
    }
}
