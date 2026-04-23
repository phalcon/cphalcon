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

namespace Phalcon\Tests\Unit\Annotations\Collection;

use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Exception;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetTest extends AbstractUnitTestCase
{
    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-27
     */
    public function testAnnotationsCollectionGet(): void
    {
        $dataAnnotation  = ['name' => 'NovAnnotation'];
        $dataAnnotation1 = ['name' => 'Phalconatation'];

        $collection = new Collection([$dataAnnotation, $dataAnnotation1]);
        $annotation = new Annotation($dataAnnotation1);

        $this->assertEquals($annotation, $collection->get('Phalconatation'));
    }

    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-27
     */
    public function testAnnotationsCollectionGetException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Collection does not have an annotation called 'NoExist'"
        );

        $collection = new Collection();
        $collection->get('NoExist');
    }
}
