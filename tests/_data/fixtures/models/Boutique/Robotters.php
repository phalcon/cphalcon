<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Boutique;

use Phalcon\Mvc\Model;

class Robotters extends Model
{
    /**
     * @Primary
     * @Identity
     * @Column(type="integer", nullable=false, mappedColumn="id")
     */
    public $code;

    /**
     * @Column(type="string", length=70, nullable=false, mappedColumn="id")
     */
    public $theName;

    /**
     * @Column(type="string", length=32, nullable=false, mappedColumn="id")
     */
    public $theType;

    /**
     * @Column(type="integer", nullable=false, mappedColumn="id")
     */
    public $theYear;

    public function initialize()
    {
        $this->setSource('robots');
    }
}
