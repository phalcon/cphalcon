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

namespace Phalcon\Tests\Unit\Translate\Adapter\Gettext;

use Phalcon\Tests\Fixtures\Traits\TranslateGettextTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

/**
 * Class NqueryCest
 *
 * @package Phalcon\Tests\Unit\Translate\Adapter\Gettext
 */
class NqueryCest
{
    use TranslateGettextTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: nquery()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterGettextNquery(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - nquery()');

        $params     = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $params);

        $expected = 'two files';
        $actual   = $translator->nquery('file', 'files', 2);
        $I->assertEquals($expected, $actual);
    }
}
