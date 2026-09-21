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

#[\Phalcon\Annotations\Router\RoutePrefix('/test')]
#[\Sample\Other\Marker('outside')]
class TestClassAttributes
{
    #[\Phalcon\Annotations\Models\MetaData\Primary]
    public const STATUS = 'active';

    #[\Phalcon\Annotations\Models\MetaData\Column(type: 'varchar', length: 70)]
    protected $name;

    #[\Phalcon\Annotations\Router\Get('/test/index', name: 'test-index')]
    public function indexAction()
    {
    }

    public function plainAction()
    {
    }
}
