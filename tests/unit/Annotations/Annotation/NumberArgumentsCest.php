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

namespace Phalcon\Test\Unit\Annotations\Annotation;

use UnitTester;

class NumberArgumentsCest
{
    /**
     * Tests Phalcon\Annotations\Annotation :: numberArguments()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAnnotationNumberArguments(UnitTester $I)
    {
        $I->wantToTest('Annotations\Annotation - numberArguments()');

        $I->skipTest('Need implementation');
    }
}
