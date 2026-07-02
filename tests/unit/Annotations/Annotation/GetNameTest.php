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

namespace Phalcon\Tests\Unit\Annotations\Annotation;

use Phalcon\Annotations\Annotation;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class GetNameTest extends AbstractUnitTestCase
{
    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function testAnnotationsAnnotationGetName(): void
    {
        $name = 'NovAnnotation';

        $annotation = new Annotation(
            [
                'name' => $name,
            ]
        );

        $this->assertEquals($name, $annotation->getName());
    }
}
