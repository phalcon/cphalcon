<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Config\Adapter\Yaml;

use UnitTester;

/**
 * Class MergeCest
 */
class MergeCest
{
    /**
     * Tests Phalcon\Config\Adapter\Yaml :: merge()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configAdapterYamlMerge(UnitTester $I)
    {
        $I->wantToTest("Config\Adapter\Yaml - merge()");
        $I->skipTest("Need implementation");
    }
}
