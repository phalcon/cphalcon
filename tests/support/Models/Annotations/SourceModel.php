<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Models\Annotations;

use Phalcon\Annotations\Models\MetaData\Column;
use Phalcon\Annotations\Models\MetaData\Identity;
use Phalcon\Annotations\Models\MetaData\Primary;
use Phalcon\Annotations\Models\MetaData\Source;
use Phalcon\Mvc\Model;

/**
 * @Source("docblock_records")
 */
#[Source('attribute_records')]
class SourceModel extends Model
{
    /**
     * @Primary
     * @Identity
     * @Column(type="integer")
     */
    #[Primary]
    #[Identity]
    #[Column(type: 'integer')]
    public $id;

    /**
     * @Column(type="varchar", length=70)
     */
    #[Column(type: 'varchar', length: 70)]
    public $name;
}
