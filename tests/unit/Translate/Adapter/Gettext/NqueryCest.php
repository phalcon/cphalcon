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

namespace Phalcon\Test\Unit\Translate\Adapter\Gettext;

use ArrayAccess;
use Phalcon\Test\Fixtures\Traits\TranslateGettextTrait;
use Phalcon\Translate\Adapter\AdapterInterface;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

class NqueryCest
{
    use TranslateGettextTrait;
    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: nquery()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateAdapterGettextNquery(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - nquery()');

        $params     = $this->getGettextConfig();
        $translator = new Gettext(
            new InterpolatorFactory(),
            $params
        );

        $I->assertEquals('two files', $translator->nquery('file', 'files', 2));
    }
}
