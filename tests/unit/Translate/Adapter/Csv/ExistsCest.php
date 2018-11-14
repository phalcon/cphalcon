<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate\Adapter\Csv;

use Phalcon\Test\Fixtures\Traits\TranslateTrait;
use Phalcon\Translate\Adapter\Csv;
use UnitTester;

class ExistsCest
{
    use TranslateTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Csv :: exists()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testExists(UnitTester $I)
    {
        $params     = $this->getCsvConfig()['ru'];
        $translator = new Csv($params);

        $actual = $translator->exists('Hello!');
        $I->assertTrue($actual);
    }
}
