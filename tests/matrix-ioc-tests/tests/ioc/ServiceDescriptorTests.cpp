#include "gtest/gtest.h"
#include "ServiceDescriptor.h"
#include "Rectangle.h"
#include "Circle.h"

namespace Connectivity
{
	TEST(ServiceDescriptorTests, Constructor) {
		ServiceDescriptor descriptor;

		ASSERT_EQ(ServiceLifetime::Singleton, descriptor.lifetime);

		EXPECT_EQ(nullptr, descriptor.instance);
		EXPECT_EQ(nullptr, descriptor.creatorContext);		
	}

	TEST(ServiceDescriptorTests, WithName) {
		ServiceDescriptor descriptor;

		EXPECT_EQ("", descriptor.name);

		descriptor.withName("test");

		EXPECT_EQ("test", descriptor.name);
	}

	TEST(ServiceDescriptorTests, TransientWithDeclare) {
		auto descriptor = ServiceDescriptor::Transient<Rectangle>();
		const TypeInfo* rectType = TypeInfo::From<Rectangle>();

		ASSERT_EQ(ServiceLifetime::Transient, descriptor->lifetime);
		ASSERT_EQ(rectType->name, descriptor->serviceType->name);
		ASSERT_EQ(rectType->name, descriptor->implementationType->name);

		auto rect = descriptor->getInstance<Rectangle>();
		ASSERT_EQ("Rectangle", rect->name);
	}

	TEST(ServiceDescriptorTests, TransientWithImplementation) {
		auto descriptor = ServiceDescriptor::Transient<Shape,Rectangle>();
		const TypeInfo* rectType = TypeInfo::From<Rectangle>();
		const TypeInfo* shapeType = TypeInfo::From<Shape>();

		ASSERT_EQ(ServiceLifetime::Transient, descriptor->lifetime);
		ASSERT_EQ(shapeType->name, descriptor->serviceType->name);
		ASSERT_EQ(rectType->name, descriptor->implementationType->name);

		auto rect = descriptor->getInstance<Shape>();
		ASSERT_EQ("Rectangle", rect->name);

		auto rect1 = descriptor->getInstance<Shape>();

		ASSERT_NE(rect->id, rect1->id);
	}

	TEST(ServiceDescriptorTests, TransientWithFactory) {
		auto descriptor = ServiceDescriptor::Transient<Shape, Rectangle>(
			ParameterInstanceFactory<Rectangle>("rect", 20, 30), "Large"
			);

		const TypeInfo* rectType = TypeInfo::From<Rectangle>();
		const TypeInfo* shapeType = TypeInfo::From<Shape>();

		ASSERT_EQ(ServiceLifetime::Transient, descriptor->lifetime);
		ASSERT_EQ(shapeType->name, descriptor->serviceType->name);
		ASSERT_EQ(rectType->name, descriptor->implementationType->name);
		ASSERT_EQ("Large", descriptor->name);

		auto rect = descriptor->getInstance<Rectangle>();
		ASSERT_EQ("rect", rect->name);
		ASSERT_EQ(20, rect->width);
		ASSERT_EQ(30, rect->height);


		auto rect1 = descriptor->getInstance<Shape>();
		ASSERT_NE(rect->id, rect1->id);
	}

	TEST(ServiceDescriptorTests, TransientWithCreatorContext) {
		
		//InstanceCreatorContext context;
		auto descriptor = ServiceDescriptor::Transient<Shape, Rectangle>(
			ParameterInstanceFactory<Rectangle>("rect", 20, 30), "Large"
			);
		const TypeInfo* rectType = TypeInfo::From<Rectangle>();
		const TypeInfo* shapeType = TypeInfo::From<Shape>();

		ASSERT_EQ(ServiceLifetime::Transient, descriptor->lifetime);
		ASSERT_EQ(shapeType->name, descriptor->serviceType->name);
		ASSERT_EQ(rectType->name, descriptor->implementationType->name);
		ASSERT_EQ("Large", descriptor->name);

		auto rect = descriptor->getInstance<Rectangle>();
		ASSERT_EQ("rect", rect->name);
		ASSERT_EQ(20, rect->width);
		ASSERT_EQ(30, rect->height);


		auto rect1 = descriptor->getInstance<Shape>();
		ASSERT_NE(rect->id, rect1->id);
	}

	TEST(ServiceDescriptorTests, SingletonWithDeclare) {
		auto descriptor = ServiceDescriptor::Singleton<Rectangle>();
		const TypeInfo* rectType = TypeInfo::From<Rectangle>();

		ASSERT_EQ(ServiceLifetime::Singleton, descriptor->lifetime);
		ASSERT_EQ(rectType->name, descriptor->serviceType->name);
		ASSERT_EQ(rectType->name, descriptor->implementationType->name);

		auto rect = descriptor->getInstance<Rectangle>();
		ASSERT_EQ("Rectangle", rect->name);
	}

	TEST(ServiceDescriptorTests, SingletonWithImplementation) {
		auto descriptor = ServiceDescriptor::Singleton<Shape, Rectangle>();
		const TypeInfo* rectType = TypeInfo::From<Rectangle>();
		const TypeInfo* shapeType = TypeInfo::From<Shape>();

		ASSERT_EQ(ServiceLifetime::Singleton, descriptor->lifetime);
		ASSERT_EQ(shapeType->name, descriptor->serviceType->name);
		ASSERT_EQ(rectType->name, descriptor->implementationType->name);

		auto rect = descriptor->getInstance<Shape>();
		ASSERT_EQ("Rectangle", rect->name);

		auto rect1 = descriptor->getInstance<Shape>();

		ASSERT_EQ(rect->id, rect1->id);
	}

	TEST(ServiceDescriptorTests, SingletonWithFactory) {
		auto descriptor = ServiceDescriptor::Singleton<Shape, Rectangle>(
			ParameterInstanceFactory<Rectangle>("rect", 20, 30), "Large"
			);
		const TypeInfo* rectType = TypeInfo::From<Rectangle>();
		const TypeInfo* shapeType = TypeInfo::From<Shape>();

		ASSERT_EQ(ServiceLifetime::Singleton, descriptor->lifetime);
		ASSERT_EQ(shapeType->name, descriptor->serviceType->name);
		ASSERT_EQ(rectType->name, descriptor->implementationType->name);
		ASSERT_EQ("Large", descriptor->name);

		auto rect = descriptor->getInstance<Rectangle>();
		ASSERT_EQ("rect", rect->name);
		ASSERT_EQ(20, rect->width);
		ASSERT_EQ(30, rect->height);


		auto rect1 = descriptor->getInstance<Shape>();
		ASSERT_EQ(rect->id, rect1->id);
	}

	TEST(ServiceDescriptorTests, SingletonWithCreatorContext) {

		//InstanceCreatorContext context;
		auto descriptor = ServiceDescriptor::Singleton<Shape, Rectangle>(
			ParameterInstanceFactory<Rectangle>("rect", 20, 30), "Large"
			);
		const TypeInfo* rectType = TypeInfo::From<Rectangle>();
		const TypeInfo* shapeType = TypeInfo::From<Shape>();

		ASSERT_EQ(ServiceLifetime::Singleton, descriptor->lifetime);
		ASSERT_EQ(shapeType->name, descriptor->serviceType->name);
		ASSERT_EQ(rectType->name, descriptor->implementationType->name);
		ASSERT_EQ("Large", descriptor->name);

		auto rect = descriptor->getInstance<Rectangle>();
		ASSERT_EQ("rect", rect->name);
		ASSERT_EQ(20, rect->width);
		ASSERT_EQ(30, rect->height);


		auto rect1 = descriptor->getInstance<Shape>();
		ASSERT_EQ(rect->id, rect1->id);
	}
}